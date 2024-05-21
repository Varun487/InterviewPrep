import sys
import os


def create_folder_structure(name):
	try:
		os.mkdir(name)
		with open(f'./{name}/{name}.py', 'w') as fp:
			pass
		with open(f'./{name}/{name}.cpp', 'w') as fp:
			pass
		print(f"Created {name} folder and files")
	except FileExistsError:
		print(f"Problem {name} already exists!")

create_folder_structure(sys.argv[1])
