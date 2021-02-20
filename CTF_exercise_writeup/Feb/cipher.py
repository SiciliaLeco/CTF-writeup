import itertools

from Crypto.Cipher import AES
from binascii import hexlify, unhexlify, b2a_base64, a2b_base64

IV = "helloworldcs2107"


def pad_key(key: str):
    """Pad the key with 0s"""

    # Variables
    length = len(key)
    default_length = 32

    # Check if key exceeds length
    if length > 32:
        # raise ValueError("Key value too long") # cause exception
        return "00000000000000000000000000000000"

    # Padding for Cipher
    if length < default_length:
        key += '0' * (default_length - length)

    # Return the padded key
    return key


def create_cipher(key, iv):
    """Create the cipher to decode the text"""
    return AES.new(key.encode(), AES.MODE_CBC, iv.encode())


def encrypt(key: str, iv: str, message: str):
    """Encrypt the text with iv"""
    cipher = create_cipher(key, iv)

    # Cipher text in base64
    return b2a_base64(cipher.encrypt(message.encode())).decode()


def decrypt(key: str, iv: str, cipher_text: str):
    """Decrypt the text with iv"""
    ct = a2b_base64(cipher_text)
    cipher = create_cipher(key, iv)
    return cipher.decrypt(ct).decode(errors='ignore') # errors= ignore to do with unicodeDeocdeError


def generate_cipher(permutation, separator, title):
    '''
    generate cipher
    :param permutation:
    :param separator:
    :param title: whether use title case to generate cipher
    :return:
    '''
    key = ""
    with open("ciphertext") as file:
        cipher_text = file.read()
    for s in separator:
        for word in permutation:
            if title == True: #title case
                templist = []
                for i in word:
                    templist.append(i.title())
                key = s.join(templist)
                info = decrypt(pad_key(key), IV, cipher_text)
                if "cs2107" in info:
                    print("found:{}".format(info))
                    return True
            else:
                key=s.join(word)
                info=decrypt(pad_key(key), IV, cipher_text)
                if "cs2107" in info:
                    print("found:{}".format(info))
                    return True
    return False

def generate_test(times, word):
    separator = ["", "_", "-"]
    permutation = list(itertools.permutations(word, times))
    answer = generate_cipher(permutation, separator, True)
    answer = generate_cipher(permutation, separator, False) or answer
    return answer

if __name__ == '__main__':
    word = ["tan", 'ah', 'huey', 'petya', 'rose', 'accountant', 'ng', 'mary', 'dahlias', '08', '31', '1976', 'stuxnet',
     'wannacry',
     'blue', 'afternoon', 'walk', 'beach', '32', '6', '200', 'taxes', 'financial', 'planning', 'manage', 'finances',
     'math',
     'accounting', 'leadership', 'attention', 'to', 'detail', '70%', '90%', '70', '90', '0', '2000', 'shinn', 'marlar',
     'sandar', '3235', 'security', 'drive', 'block', '2107C', '9456', '1256', 'tanpetya76', '@gmail.com', 'august',
     'tanpetya', '76', '94561256', '08311976', 'tanahhueypetya', 'tanahhuey']

    for i in range(10):
        print("word number:{}".format(i + 1))
        result = generate_test(i + 1, word)
        if result == False: # not found the result
            continue
        else:
            break # end the progress