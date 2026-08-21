#!/usr/bin/env python3
"""
Competitive Programming Helper CLI (cp_tool)
Author: Antigravity Assistant & Gabriel Frigo
"""

import os
import sys
import time
import shutil
import argparse
import subprocess
from pathlib import Path
import difflib

# ANSI Colors
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
MAGENTA = "\033[95m"
GRAY = "\033[90m"

REPO_ROOT = Path(__file__).resolve().parent.parent

TEMPLATES = {
    "cpp": REPO_ROOT / "templates" / "cpp" / "standard" / "main.cpp",
    "cpp-loop": REPO_ROOT / "templates" / "cpp" / "multiple-cases" / "main.cpp",
    "py": REPO_ROOT / "templates" / "python" / "main.py",
    "rs": REPO_ROOT / "templates" / "rust" / "rustc" / "main.rs",
    "c": REPO_ROOT / "templates" / "c" / "standard" / "main.c",
}

DEFAULT_MAKEFILE = """CC := g++
EXT := cpp
TARGET := main
INPUT := ./input.txt
EXPECTED := ./expected.txt

CXXFLAGS := -std=c++23 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined
STACK_FLAG := -Wl,-z,stack-size=268435456

.PHONY: all run test clean clip

all: $(TARGET)

$(TARGET): $(TARGET).$(EXT)
\t$(CC) $(CXXFLAGS) $(STACK_FLAG) $< -o $@

run: $(TARGET)
\t@cat $(INPUT) | ./$(TARGET)

test:
\t@python3 $(REPO_ROOT)/tools/cp_tool.py run .

clip:
\t@python3 $(REPO_ROOT)/tools/cp_tool.py clip $(TARGET).$(EXT)

clean:
\trm -f $(TARGET) *.exe *.out
"""

def get_clipboard_command():
    if shutil.which("wl-copy"):
        return ["wl-copy"]
    elif shutil.which("xclip"):
        return ["xclip", "-selection", "clipboard"]
    elif shutil.which("clip.exe"):
        return ["clip.exe"]
    elif shutil.which("pbcopy"):
        return ["pbcopy"]
    return None

def find_solution_file(target_dir: Path):
    if target_dir.is_file():
        return target_dir

    candidates = [
        "main.cpp", "main.py", "main.rs", "main.c",
        "solution.cpp", "solution.py", "sol.cpp", "sol.py"
    ]
    for c in candidates:
        candidate_path = target_dir / c
        if candidate_path.exists():
            return candidate_path

    # Search for any .cpp, .py, .rs, .c
    for ext in [".cpp", ".py", ".rs", ".c"]:
        files = list(target_dir.glob(f"*{ext}"))
        if files:
            return files[0]
    return None

def cmd_new(args):
    """Create a new problem or contest structure."""
    target_path = Path(args.path)
    lang = args.lang or "cpp"
    problems = args.problems or ["A"]

    if not target_path.is_absolute():
        target_path = Path.cwd() / target_path

    print(f"{BOLD}{CYAN}Creating new setup at:{RESET} {target_path}")

    for p in problems:
        p_dir = target_path / p if len(problems) > 1 or args.create_subdir else target_path
        p_dir.mkdir(parents=True, exist_ok=True)

        # Create input.txt
        input_file = p_dir / "input.txt"
        if not input_file.exists():
            input_file.write_text("")

        # Create expected.txt
        expected_file = p_dir / "expected.txt"
        if not expected_file.exists():
            expected_file.write_text("")

        # Create solution file from template
        source_ext = "cpp" if lang.startswith("cpp") else lang
        source_file = p_dir / f"main.{source_ext}"
        if not source_file.exists():
            template_path = TEMPLATES.get(lang, TEMPLATES["cpp"])
            if template_path.exists():
                shutil.copy(template_path, source_file)
            else:
                source_file.write_text("#include <iostream>\n\nint main() {\n    return 0;\n}\n")

        # Create Makefile
        makefile = p_dir / "Makefile"
        if not makefile.exists():
            makefile_content = DEFAULT_MAKEFILE.replace("$(REPO_ROOT)", str(REPO_ROOT))
            makefile.write_text(makefile_content)

        print(f"  {GREEN}✔{RESET} Created {p_dir.relative_to(REPO_ROOT) if p_dir.is_relative_to(REPO_ROOT) else p_dir}")

def cmd_run(args):
    """Compile, execute and test against input.txt / expected.txt."""
    target = Path(args.target or ".").resolve()
    source_file = find_solution_file(target)

    if not source_file:
        print(f"{RED}Error:{RESET} No solution file found in {target}")
        sys.exit(1)

    work_dir = source_file.parent
    input_file = work_dir / "input.txt"
    expected_file = work_dir / "expected.txt"

    print(f"{BOLD}{CYAN}Target:{RESET} {source_file.relative_to(REPO_ROOT) if source_file.is_relative_to(REPO_ROOT) else source_file}")

    ext = source_file.suffix
    exe_file = work_dir / "main_bin"

    # Compile if needed
    if ext == ".cpp":
        print(f"{GRAY}Compiling C++23...{RESET}")
        compile_cmd = [
            "g++", "-std=c++23", "-O2", "-Wall", "-Wextra",
            "-Wl,-z,stack-size=268435456",
            str(source_file), "-o", str(exe_file)
        ]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        if res.returncode != 0:
            print(f"{RED}{BOLD}Compilation Failed:{RESET}\n{res.stderr}")
            sys.exit(1)
        run_cmd = [str(exe_file)]
    elif ext == ".c":
        compile_cmd = ["gcc", "-O2", "-Wall", str(source_file), "-o", str(exe_file)]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        if res.returncode != 0:
            print(f"{RED}{BOLD}Compilation Failed:{RESET}\n{res.stderr}")
            sys.exit(1)
        run_cmd = [str(exe_file)]
    elif ext == ".rs":
        compile_cmd = ["rustc", "-O", str(source_file), "-o", str(exe_file)]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        if res.returncode != 0:
            print(f"{RED}{BOLD}Compilation Failed:{RESET}\n{res.stderr}")
            sys.exit(1)
        run_cmd = [str(exe_file)]
    elif ext == ".py":
        run_cmd = ["python3", str(source_file)]
    else:
        print(f"{RED}Unsupported file extension:{RESET} {ext}")
        sys.exit(1)

    # Input handling
    stdin_data = ""
    if input_file.exists():
        stdin_data = input_file.read_text()

    # Execution
    start_time = time.perf_counter()
    try:
        proc = subprocess.run(
            run_cmd,
            input=stdin_data,
            capture_output=True,
            text=True,
            timeout=args.timeout or 5.0,
            cwd=work_dir
        )
        elapsed_ms = (time.perf_counter() - start_time) * 1000.0
    except subprocess.TimeoutExpired:
        print(f"\n{RED}{BOLD}[ TLE ] Time Limit Exceeded (> {args.timeout or 5.0}s){RESET}")
        if exe_file.exists(): exe_file.unlink()
        sys.exit(1)

    if exe_file.exists():
        exe_file.unlink()

    if proc.returncode != 0:
        print(f"\n{RED}{BOLD}[ RTE ] Runtime Error (exit code {proc.returncode}):{RESET}\n{proc.stderr}")
        sys.exit(1)

    output = proc.stdout.strip()

    print(f"{BOLD}{GRAY}--- Output ({elapsed_ms:.1f} ms) ---{RESET}")
    print(output if output else f"{GRAY}(No output){RESET}")
    print(f"{BOLD}{GRAY}--------------------------{RESET}")

    # Check against expected.txt if exists and not empty
    if expected_file.exists() and expected_file.read_text().strip():
        expected = expected_file.read_text().strip()
        if output == expected:
            print(f"\n{BOLD}{GREEN}[ AC ] Output matches expected.txt! ({elapsed_ms:.1f} ms){RESET}\n")
        else:
            print(f"\n{BOLD}{RED}[ WA ] Output differs from expected.txt!{RESET}")
            diff = difflib.unified_diff(
                expected.splitlines(keepends=True),
                output.splitlines(keepends=True),
                fromfile="expected.txt",
                tofile="actual_output"
            )
            print("".join(diff))

def cmd_clip(args):
    """Copy solution source code to clipboard."""
    target = Path(args.target or ".").resolve()
    source_file = find_solution_file(target)

    if not source_file:
        print(f"{RED}Error:{RESET} No solution file found in {target}")
        sys.exit(1)

    clip_cmd = get_clipboard_command()
    if not clip_cmd:
        print(f"{YELLOW}Warning:{RESET} No clipboard utility found (wl-copy, xclip, pbcopy, clip.exe).")
        return

    content = source_file.read_text()
    proc = subprocess.run(clip_cmd, input=content, text=True)
    if proc.returncode == 0:
        print(f"{BOLD}{GREEN}✔ Copied {source_file.name} to clipboard! ({len(content)} bytes){RESET}")
    else:
        print(f"{RED}Failed to copy to clipboard.{RESET}")

def scan_stats():
    """Scan the repository and return detailed statistics."""
    stats = {
        "languages": {"cpp": 0, "py": 0, "rs": 0, "c": 0},
        "competitions": {},
        "practice": {},
        "algorithms": 0,
        "total_solutions": 0
    }

    ext_map = {".cpp": "cpp", ".py": "py", ".rs": "rs", ".c": "c"}

    for root, dirs, files in os.walk(REPO_ROOT):
        # Ignore git, hidden, legacy notes, docs
        if any(p in root for p in [".git", "legacy-notes", "templates/atcoder-lib"]):
            continue

        rel_root = Path(root).relative_to(REPO_ROOT)
        parts = rel_root.parts

        for f in files:
            ext = os.path.splitext(f)[1]
            if parts and parts[0] == "algorithms" and ext in [".hpp", ".cpp", ".py"]:
                stats["algorithms"] += 1

            if ext in ext_map:
                lang = ext_map[ext]
                stats["languages"][lang] += 1
                stats["total_solutions"] += 1

                if parts and parts[0] == "competitions" and len(parts) > 1:
                    comp_name = parts[1]
                    stats["competitions"][comp_name] = stats["competitions"].get(comp_name, 0) + 1
                elif parts and parts[0] == "practice" and len(parts) > 1:
                    platform = parts[1]
                    stats["practice"][platform] = stats["practice"].get(platform, 0) + 1

    return stats

def cmd_stats(args):
    """Display repository statistics."""
    stats = scan_stats()

    print(f"\n{BOLD}{CYAN}=========================================={RESET}")
    print(f"{BOLD}{MAGENTA} 🚀 Competitive Programming Repository Stats{RESET}")
    print(f"{BOLD}{CYAN}=========================================={RESET}\n")

    print(f"{BOLD}Total Solutions Tracked:{RESET} {GREEN}{stats['total_solutions']}{RESET}\n")

    print(f"{BOLD}Languages Distribution:{RESET}")
    for lang, count in stats["languages"].items():
        bar = "█" * (count // 5)
        print(f"  {CYAN}{lang.upper():6s}{RESET} : {count:4d}  {GRAY}{bar}{RESET}")

    print(f"\n{BOLD}Competitions Solved:{RESET}")
    for comp, count in sorted(stats["competitions"].items()):
        print(f"  {YELLOW}• {comp:20s}{RESET} : {count:3d} problems")

    print(f"\n{BOLD}Practice by Platform:{RESET}")
    for plat, count in sorted(stats["practice"].items()):
        print(f"  {GREEN}• {plat:20s}{RESET} : {count:3d} problems")

    print(f"\n{BOLD}Algorithms in Library:{RESET} {CYAN}{stats['algorithms']}{RESET} components\n")

def main():
    parser = argparse.ArgumentParser(description="Competitive Programming Helper Tool")
    subparsers = parser.add_subparsers(dest="command", help="Command to run")

    # New problem/contest
    p_new = subparsers.add_parser("new", help="Create new problem or contest directory")
    p_new.add_argument("path", help="Path to create problem/contest in")
    p_new.add_argument("problems", nargs="*", help="Problem names (e.g. A B C D)")
    p_new.add_argument("--lang", default="cpp", choices=["cpp", "cpp-loop", "py", "rs", "c"], help="Template language")
    p_new.add_argument("--create-subdir", action="store_true", help="Always create subdirectories for problems")

    # Run/Test
    p_run = subparsers.add_parser("run", help="Compile, run and test a solution")
    p_run.add_argument("target", nargs="?", default=".", help="Target directory or file")
    p_run.add_argument("--timeout", type=float, default=5.0, help="Execution timeout in seconds")

    # Clip
    p_clip = subparsers.add_parser("clip", help="Copy solution to clipboard")
    p_clip.add_argument("target", nargs="?", default=".", help="Target directory or file")

    # Stats
    p_stats = subparsers.add_parser("stats", help="Display repository statistics")

    args = parser.parse_args()

    if args.command == "new":
        cmd_new(args)
    elif args.command == "run" or args.command == "test":
        cmd_run(args)
    elif args.command == "clip":
        cmd_clip(args)
    elif args.command == "stats":
        cmd_stats(args)
    else:
        parser.print_help()

if __name__ == "__main__":
    main()
