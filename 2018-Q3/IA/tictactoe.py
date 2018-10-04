MAX = 'x'
MIN = 'o'


def get_player(s):
    return MAX if len([1 for i in s if i == ' ']) % 2 == 1 else MIN


def next_player(p):
    return MAX if p == MIN else MIN


def get_actions(s):
    return [i for i in range(9) if s[i] == ' ']


def result(s, a):
    player = get_player(s)
    s2 = list(s)
    s2[a] = player

    return s2


def is_winning_state(s, player):
    aux = [player] * 3
    if s[0:3] == aux or \
            s[3:6] == aux or \
            s[6:9] == aux or \
            s[0:9:3] == aux or \
            s[1:9:3] == aux or \
            s[2:9:3] == aux or \
            s[2:8:2] == aux or \
            s[0:9:4] == aux:
        return True
    else:
        return False


def terminal(s):
    if is_winning_state(s, MAX) or is_winning_state(s, MIN):
        return True

    if ' ' not in s:
        return True

    return False


def utility(s):
    if is_winning_state(s, MAX):
        return 1
    if is_winning_state(s, MIN):
        return -1
    return 0


def maxval(s):
    if terminal(s):
        return None, utility(s)

    best_utility = float("-Inf")
    best_action = None

    actions = get_actions(s)
    for action in actions:
        s2 = result(s, action)
        _, current_utility = minval(s2)
        if current_utility >= best_utility:
            best_utility = current_utility
            best_action = action
        if best_utility == 1:  # Maximum utility
            break

    return best_action, best_utility


def minval(s):
    if terminal(s):
        return None, utility(s)

    best_utility = float("Inf")
    best_action = None

    actions = get_actions(s)
    for action in actions:
        s2 = result(s, action)
        _, current_utility = maxval(s2)
        if current_utility <= best_utility:
            best_utility = current_utility
            best_action = action
        if best_utility == -1:  # Minimum utility
            break

    return best_action, best_utility


def minmax(s):
    p = get_player(s)
    if p == MAX:
        return maxval(s)
    if p == MIN:
        return minval(s)


def print_s(s):
    print(" {} | {} | {} \n"
          " 0 | 1 | 2 \n"
          "-----------\n"
          " {} | {} | {} \n"
          " 3 | 4 | 5 \n"
          "-----------\n"
          " {} | {} | {} \n"
          " 6 | 7 | 8 \n".format(*s))


def ai_play(s):
    a, _ = minmax(s)
    return a


def user_play(s):
    a = int(input())
    return a


if __name__ == "__main__":
    s = [' ', ' ', ' ',
         ' ', ' ', ' ',
         ' ', ' ', ' ']
    print_s(s)

    players = [
        ("USER", user_play),
        ("AI", ai_play)
    ]

    while not terminal(s):
        for name, method in players:
            print("{} -> ".format(name))
            a = method(s)
            s = result(s, a)
            print_s(s)

            if terminal(s):
                break

    if is_winning_state(s, MAX):
        print("PLAYER '{}' WON!".format(MAX))
    elif is_winning_state(s, MIN):
        print("PLAYER '{}' WON!".format(MIN))
    else:
        print("TIE!")