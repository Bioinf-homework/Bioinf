import ctypes
so = ctypes.cdll.LoadLibrary
lib = so("./libk.so")
rst = lib.test(int(i),int(j))

print(rst)
size = -1
rst = ctypes.string_at(rst, size)
print(rst.decode('utf-8'))