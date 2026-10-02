#!/usr/bin/env python3
"""
Unit tests for tools/cp_tool.py CLI
"""

import sys
import tempfile
import unittest
from pathlib import Path
import subprocess

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))

import cp_tool


class TestCPTool(unittest.TestCase):
    def test_scan_stats(self):
        """Ensure scan_stats traverses the repo and calculates metrics."""
        stats = cp_tool.scan_stats()
        self.assertIn("languages", stats)
        self.assertIn("competitions", stats)
        self.assertIn("practice", stats)
        self.assertIn("algorithms", stats)
        self.assertIn("total_solutions", stats)
        self.assertGreater(stats["total_solutions"], 0)
        self.assertGreater(stats["algorithms"], 0)
        self.assertGreater(stats["languages"]["cpp"], 0)

    def test_new_and_run_ac(self):
        """Test creating a problem via cpt new and verifying AC with cpt run."""
        with tempfile.TemporaryDirectory() as tmpdir:
            tmppath = Path(tmpdir)
            target = tmppath / "problem_a"

            # Simula cpt new
            class ArgsNew:
                path = str(target)
                problems = ["A"]
                lang = "py"
                create_subdir = True

            cp_tool.cmd_new(ArgsNew())

            prob_dir = target / "A"
            self.assertTrue(prob_dir.exists())
            self.assertTrue((prob_dir / "main.py").exists())
            self.assertTrue((prob_dir / "input.txt").exists())
            self.assertTrue((prob_dir / "expected.txt").exists())
            self.assertTrue((prob_dir / "Makefile").exists())

            # Escreve código python de teste
            (prob_dir / "main.py").write_text("a = input().strip()\nprint(f'Hello {a}')\n")
            (prob_dir / "input.txt").write_text("World\n")
            (prob_dir / "expected.txt").write_text("Hello World\n")

            # Executa cp_tool run
            res = subprocess.run(
                [sys.executable, str(REPO_ROOT / "tools" / "cp_tool.py"), "run", str(prob_dir)],
                capture_output=True,
                text=True
            )
            self.assertEqual(res.returncode, 0)
            self.assertIn("[ AC ]", res.stdout)

    def test_run_wa(self):
        """Test that cpt run correctly flags Wrong Answer [ WA ]."""
        with tempfile.TemporaryDirectory() as tmpdir:
            tmppath = Path(tmpdir)
            (tmppath / "main.py").write_text("print('Wrong')\n")
            (tmppath / "input.txt").write_text("")
            (tmppath / "expected.txt").write_text("Correct\n")

            res = subprocess.run(
                [sys.executable, str(REPO_ROOT / "tools" / "cp_tool.py"), "run", str(tmppath)],
                capture_output=True,
                text=True
            )
            self.assertEqual(res.returncode, 0)
            self.assertIn("[ WA ]", res.stdout)


if __name__ == "__main__":
    unittest.main()
