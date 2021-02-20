import hashlib
import io

def GetFileMd5(filename):
    myhash = hashlib.md5()
    f = io.FileIO(filename,'rb')
    while True:
        b = f.read()
        if not b :
            break
        myhash.update(b)
    f.close()
    return myhash.hexdigest() #get result

print(GetFileMd5("existence.txt"))