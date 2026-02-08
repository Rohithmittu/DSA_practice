def findNearestDivisible(N, arr):

    for i in range(N):
        for j in range(N):
            x = arr[i][j]

            lower = (x // 5) * 5
            upper = lower + 5

            if abs(x - lower) < abs(upper - x):
                arr[i][j] = lower
            else:
                arr[i][j] = upper


    for i in range(N):
        for j in range(N):
            print(arr[i][j], end=" ")
        print()


def main():
    size = int(input())
    array = []
    for i in range(size):
        row = list(map(int, input().split()))
        array.append(row)

    findNearestDivisible(size, array)


main()

