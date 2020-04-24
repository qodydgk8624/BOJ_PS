# 2675 문자열 반복

n = int(input())
for i in range(n):
    rpt, string = input().split()
    rpt = int(rpt)
    for rpt_str in string:
        _ = rpt_str * rpt
        print(_, end="")
    print()
