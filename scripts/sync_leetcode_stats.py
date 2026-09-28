#!/usr/bin/env python3
"""Synchronize README LeetCode stats block from stats.json."""

from __future__ import annotations

import argparse
import json
from pathlib import Path

START_MARKER = "<!---LeetCode Stats Start-->"
END_MARKER = "<!---LeetCode Stats End-->"


def render_stats_block(easy: int, medium: int, hard: int) -> str:
    total = easy + medium + hard
    return "\n".join(
        [
            START_MARKER,
            "## LeetCode Stats",
            "",
            "| Difficulty | Solved |",
            "| --- | ---: |",
            f"| Easy | {easy} |",
            f"| Medium | {medium} |",
            f"| Hard | {hard} |",
            f"| Total | {total} |",
            "",
            "_Auto-synced from `stats.json` by GitHub Actions._",
            "",
        ]
    )


def load_stats(stats_path: Path) -> tuple[int, int, int]:
    data = json.loads(stats_path.read_text(encoding="utf-8"))
    leetcode = data.get("leetcode", {})
    easy = int(leetcode.get("easy", 0))
    medium = int(leetcode.get("medium", 0))
    hard = int(leetcode.get("hard", 0))

    if min(easy, medium, hard) < 0:
        raise ValueError("LeetCode stats values must be non-negative integers")

    return easy, medium, hard


def update_readme(readme_path: Path, stats_block: str) -> bool:
    content = readme_path.read_text(encoding="utf-8")

    start_index = content.find(START_MARKER)
    end_index = content.find(END_MARKER)

    if start_index == -1 or end_index == -1 or start_index > end_index:
        raise ValueError("Could not find valid LeetCode stats markers in README.md")

    updated = (
        content[:start_index]
        + stats_block
        + END_MARKER
        + content[end_index + len(END_MARKER) :]
    )

    if updated == content:
        return False

    readme_path.write_text(updated, encoding="utf-8")
    return True


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--check",
        action="store_true",
        help="Exit non-zero if README.md is out of sync with stats.json",
    )
    parser.add_argument("--stats", default="stats.json", help="Path to stats JSON file")
    parser.add_argument("--readme", default="README.md", help="Path to README file")
    args = parser.parse_args()

    stats_path = Path(args.stats)
    readme_path = Path(args.readme)

    easy, medium, hard = load_stats(stats_path)
    stats_block = render_stats_block(easy, medium, hard)

    content = readme_path.read_text(encoding="utf-8")
    start_index = content.find(START_MARKER)
    end_index = content.find(END_MARKER)
    if start_index == -1 or end_index == -1 or start_index > end_index:
        raise ValueError("Could not find valid LeetCode stats markers in README.md")

    expected = (
        content[:start_index]
        + stats_block
        + END_MARKER
        + content[end_index + len(END_MARKER) :]
    )

    if args.check:
        if expected != content:
            print("README.md is out of sync with stats.json")
            return 1
        print("README.md is in sync with stats.json")
        return 0

    if update_readme(readme_path, stats_block):
        print("Updated README.md LeetCode stats block")
    else:
        print("README.md LeetCode stats block already up to date")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
