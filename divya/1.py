def countLetter(str, c):  # str is the given input string and c is the given letter to count
    total = 0
    
    for ch in str:
        if ch == c:
            total += 1
            
    return total

def main():
    str = input()
    c = input()
    print(countLetter(str, c))

main()
