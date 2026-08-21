import sys

# Fast I/O & Recursion Depth
sys.setrecursionlimit(200000)
input = sys.stdin.readline

def solve():
    pass

def main():
    try:
        t_str = input().strip()
        if not t_str:
            return
        t = int(t_str)
        for _ in range(t):
            solve()
    except EOFError:
        pass

if __name__ == '__main__':
    main()
