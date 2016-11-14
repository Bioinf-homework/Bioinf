import json

data = {'age': {'<21': {'marriage': {'yes': {'sex': {'woman': 'C', 'man': 'B'}}, 'no': 'C'}}, '>21and<25': {'sex': {'woman': 'A', 'man': {'marriage': {'yes': 'B', 'no': 'C'}}}}, '>25': {'sex': {'woman': 'A', 'man': 'B'}}}}

with open("re.json" , "w") as f:
	json.dump(data, f)