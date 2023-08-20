from collections import defaultdict
n = int(input())
words = []
for _ in range(n):
    cur = input()
    words.append(cur)

hash_str= defaultdict(int)
renum = 0
re_words = 0
visited = set()
for i, v in enumerate(words):
    hash_str[v] += 1
    if v not in visited and hash_str[v] > renum:
        renum += 1
        re_words += 1
        visited.add(v)
print(re_words)