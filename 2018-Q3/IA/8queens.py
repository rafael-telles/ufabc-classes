#!/usr/bin/env python3


__author__ = "Rafael Telles"
SIZE = 8


class State(object):
    def __init__(self, s):
        self.s = s


def bfs(sts):
    goal = list(filter(is_goal, sts))
    while len(goal) == 0:
        sts = list(filter(feasible, moves(sts)))
        goal = list(filter(is_goal, sts))
    return goal[0]


def dfs(st):
    if is_goal(st):
        return st

    if not feasible(st):
        return None

    for x in range(1, SIZE + 1):
        new_st = dfs(move(x, st))
        if new_st:
            return new_st

    return None


def is_goal(st):
    return len(st[0]) == SIZE and feasible(st)


def feasible(st):
    s, t = st

    if len(s) <= 1:
        return True
    if len(s) <= SIZE and not attack(s[0], s[1:]) and feasible((s[1:], t)):
        return True
    return False


def attack(q, qs):
    return (q in qs) or (q in u_diag(qs)) or (q in l_diag(qs))


def u_diag(qs):
    return [q + i + 1 for i, q in enumerate(qs)]


def l_diag(qs):
    return [q - i - 1 for i, q in enumerate(qs)]


def move(x, st):
    s, t = st
    return s + [x], t


def moves(sts):
    return [move(x, st) for x in range(1, SIZE + 1) for st in sts]


if __name__ == "__main__":
    st = ([], [])
    st_final = bfs([st])
    # st_final = dfs(st)

    s, t = st_final
    print("_" * (SIZE * 2 + 1))
    for q in s:
        print("|_" * (q - 1) + "|o" + "|_" * (SIZE - q) + "|")
