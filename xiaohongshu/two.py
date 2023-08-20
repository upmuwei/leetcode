def is_hui(s):
    left, right = 0, len(s) - 1
    while left < right:
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            if s[left] == 'd' or s[left] == 'q' or s[left] == 'p':
                s[left] = 'b'
            if s[right] == 'd' or s[right] == 'q' or s[right] == 'p':
                s[right] = 'b'
            if s[left] == 'u':
                s[left] = 'n'
            if s[right] == 'u':
                s[right] = 'n'
            if s[left] == s[right]:
                left += 1
                right -= 1
            else:
                if (s[left] == 'w' and s[right] == 'v') or (s[left] == 'v' and s[right] == 'w'):
                    if s[left] == 'w':
                        right -= 1
                        s[left] = 'v'
                    else:
                        left += 1
                        s[right] = 'v'
                elif (s[left] == 'm' and s[right] == 'n') or (s[left] == 'n' and s[right] == 'm'):
                    if s[left] == 'm':
                        right -= 1
                        s[left] = 'n'
                    else:
                        left += 1
                        s[right] = 'n'
                else:
                    return False
    return True

s = list("wovv")
print("YES" if is_hui(s) else "NO")
s = list("bod")
print("YES" if is_hui(s) else "NO")
s = list("pdd")
print("YES" if is_hui(s) else "NO")
s = list("moom")
print("YES" if is_hui(s) else "NO")
s = list("lalalai")
print("YES" if is_hui(s) else "NO")
