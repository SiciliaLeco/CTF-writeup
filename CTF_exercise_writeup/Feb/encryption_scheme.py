import random


alphabet = r"abcdefghijklmnopqrstuvwxyz+-_0123456789{}"

def encrypt(message: str):
    random.seed(2107)
    acc = []
    for letter in message:
        shift = random.randint(0, len(alphabet))
        new_index = (alphabet.index(letter) + shift) % len(alphabet)
        print(shift, new_index)
        acc.append(alphabet[new_index])

    return "".join(acc)

def decrypt(message : str):
    # msg_dct = dict()
    # for i in range(len(alphabet)):
    #     msg_dct[alphabet[i]] = i
    ans = ""
    random.seed(2107)
    for letter in message:
        idx = alphabet.index(letter)
        shift = random.randint(0, len(alphabet))
        if idx - shift < 0:
            old_idx = idx - shift + len(alphabet)
        else:
            old_idx = idx - shift

        ans += alphabet[old_idx]

    print(ans)

if __name__ == "__main__":
    # encrypt("cs2107{")
    decrypt("e11wft9}t4q0hdjntg8x7it6")
    #     # with open('flag.txt') as file:
    #     flag = file.read().strip()
    # ct = encrypt(flag)
    # print(ct)

