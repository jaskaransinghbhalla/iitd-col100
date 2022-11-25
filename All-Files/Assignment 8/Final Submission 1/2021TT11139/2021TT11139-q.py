from typing import Tuple, List
# No other imports allowed

# PART OF THE DRIVER CODE

def input_sudoku() -> List[List[int]]:
	"""Function to take input a sudoku from stdin and return
	it as a list of lists.
	Each row of sudoku is one line.
	"""
	sudoku= list()
	for _ in range(9):
		row = list(map(int, input().rstrip(" ").split(" ")))
		sudoku.append(row)
	return sudoku

def print_sudoku(sudoku:List[List[int]]) -> None:
	"""Helper function to print sudoku to stdout
	Each row of sudoku in one line.
	"""
	for i in range(9):
		for j in range(9):
			print(sudoku[i][j], end = " ")
		print()

# You have to implement the functions below

def get_block_num(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
	"""This function takes a parameter position and returns
	the block number of the block which contains the position.
	"""
	# your code goes here
	row = pos[0]-1
	col = pos[1]-1
	y=col-col%3
	x=row-row%3
	z=x+y/3+1
	return int(z)

def get_position_inside_block(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
	"""This function takes parameter position
	and returns the index of the position inside the corresponding block.
	"""
	# your code goes here
	l=[[1,2,3],[4,5,6],[7,8,9]]
	l1=[pos[0]-1,pos[1]-1]
	while(l1[0]>2):
		l1[0]=l1[0]-3
	while(l1[1]>2):
		l1[1]=l1[1]-3
	k=l[l1[0]][l1[1]]
	return k


def get_block(sudoku:List[List[int]], x: int) -> List[int]:
	"""This function takes an integer argument x and then
	returns the x^th block of the Sudoku. Note that block indexing is
	from 1 to 9 and not 0-8.
	"""
	# your code goes here
	l=[[(0,3),(0,3)],[(0,3),(3,6)],[(0,3),(6,9)],[(3,6),(0,3)],[(3,6),(3,6)],[(3,6),(6,9)],[(6,9),(0,3)],[(6,9),(3,6)],[(6,9),(6,9)]]
	
	l1=l[x-1]
	l1_row,l1_column=l1[0],l1[1]
	answer=[]
	for x in range(l1_row[0],l1_row[1]):
		for y in range(l1_column[0],l1_column[1]):
			answer.append(sudoku[x][y])
	return answer

def get_row(sudoku:List[List[int]], i: int)-> List[int]:
	"""
	This function takes an integer argument i and then returns
	the ith row. Row indexing have been shown above.
	"""
	# your code goes here
	return sudoku[i-1]

def get_column(sudoku:List[List[int]], x: int)-> List[int]:
	"""This function takes an integer argument i and then
	returns the ith column. Column indexing have been shown above.
	"""
	# your code goes here
	ans=[]
	for t in range(0,9):
		ans.append(sudoku[t][x-1])
	return ans

def find_first_unassigned_position(sudoku : List[List[int]]) -> Tuple[int, int]:
	"""This function returns the first empty position in the Sudoku. 
	If there are more than 1 position which is empty then position with lesser
	row number should be returned. If two empty positions have same row number then the position
	with less column number is to be returned. If the sudoku is completely filled then return `(-1, -1)`.
	"""
	# your code goes here
	i=0
	while(i<9):
		j=0
		while(j<9):
			if sudoku[i][j] == 0 :
				return ((i+1,j+1))
			j+=1
		i+=1
	return((-1,-1))

def valid_list(lst: List[int])-> bool:
	"""This function takes a lists as an input and returns true if the given list is valid. 
	The list will be a single block , single row or single column only. 
	A valid list is defined as a list in which all non empty elements doesn't have a repeating element.
	"""
	# your code goes here
	ans = True
	for i in range(0,len(lst)):
		if lst[i]==0:
			continue
		elif (lst.count(lst[i])>1):
				ans = False
	return ans

def valid_sudoku(sudoku:List[List[int]])-> bool:
	"""This function returns True if the whole Sudoku is valid.
	"""
	# your code goes here
	
	for i in range(1,10):
		if(valid_list(get_row(sudoku,i)) == False or 0 in get_row(sudoku,i)):
			return False
	for j in range(1,10):
		if(valid_list(get_column(sudoku,j)) == False or 0 in get_column(sudoku,i)):
			return False
	for k in range(1,10):
		if(valid_list(get_block(sudoku,k)) == False or 0 in get_block(sudoku,i)):
			return False	
	return True



	
def get_candidates(sudoku:List[List[int]], pos:Tuple[int, int]) -> List[int]:
	"""This function takes position as argument and returns a list of all the possible values that 
	can be assigned at that position so that the sudoku remains valid at that instant.
	"""
	def unique(list1):
		unique_list = []
		for x in list1:
			if x not in unique_list:
				unique_list.append(x)
		return unique_list

	all = [1,2,3,4,5,6,7,8,9]
	ans = []
	l1 = get_row(sudoku,pos[0])
	l2 = get_column(sudoku,pos[1])
	l3 = get_block(sudoku,get_block_num(sudoku,pos))
	l = unique(l1 + l2 + l3)
	for x in all :
		if x not in l :
			ans.append(x)
	return ans
		
def make_move(sudoku:List[List[int]], pos:Tuple[int, int], num:int) -> List[List[int]]:
	"""This function fill `num` at position `pos` in the sudoku and then returns
	the modified sudoku.
	"""
	# your code goes here
	i = pos[0]
	j = pos[1]
	sudoku[i-1][j-1] = num
	return sudoku

def undo_move(sudoku:List[List[int]], pos:Tuple[int, int]):
	"""This function fills `0` at position `pos` in the sudoku and then returns
	the modified sudoku. In other words, it undoes any move that you 
	did on position `pos` in the sudoku.
	"""
	# your code goes here
	i = pos[0]
	j = pos[1]
	sudoku[i-1][j-1] = 0
	return sudoku

def sudoku_solver(sudoku: List[List[int]]) -> Tuple[bool, List[List[int]]]:
	""" This is the main Sudoku solver. This function solves the given incomplete Sudoku and returns 
	true as well as the solved sudoku if the Sudoku can be solved i.e. after filling all the empty positions the Sudoku remains valid.
	It return them in a tuple i.e. `(True, solved_sudoku)`.

	However, if the sudoku cannot be solved, it returns False and the same sudoku that given to solve i.e. `(False, original_sudoku)`
	"""
	# your code goes here
	if (find_first_unassigned_position(sudoku) == (-1,-1)):
		return (valid_sudoku(sudoku),sudoku)
	change = find_first_unassigned_position(sudoku)
	candidates = get_candidates(sudoku,change)
	for each in candidates :
		sudoku = make_move(sudoku,change,each)
		poss,sudoku = sudoku_solver(sudoku)
		if poss == False:
			undo_move(sudoku,change)
		else:
			return(valid_sudoku(sudoku), sudoku)
	return(valid_sudoku(sudoku), sudoku)
	# to complete this function, you may define any number of helper functions.
	# However, we would be only calling this function to check correctness.


# PLEASE NOTE:
# We would be importing your functions and checking the return values in the autograder.
# However, note that you must not print anything in the functions that you define above before you 
# submit your code since it may result in undefined behaviour of the autograder.

# def in_lab_component(sudoku: List[List[int]]):
	# print("Testcases for In Lab evaluation")
	# print("Get Block Number:")
	# print(get_block_num(sudoku,(4,4)))
	# print(get_block_num(sudoku,(7,2)))
	# print(get_block_num(sudoku,(2,6)))
	# print("Get Block:")
	# print(get_block(sudoku,3))
	# print(get_block(sudoku,5))
	# print(get_block(sudoku,9))
	# print("Get Row:")
	# print(get_row(sudoku,3))
	# print(get_row(sudoku,5))
	# print(get_row(sudoku,9))

# Following is the driver code
# you can edit the following code to check your performance.
if __name__ == "__main__":

	# Input the sudoku from stdin
	sudoku = input_sudoku()

	# Try to solve the sudoku
	possible, sudoku = sudoku_solver(sudoku)

	# The following line is for the in-lab component
	#in_lab_component(sudoku)
	# Show the result of the same to your TA to get your code evaulated

	# Check if it could be solved
	if possible:
		print("Found a valid solution for the given sudoku :)")
		print_sudoku(sudoku)
	else:
		print("The given sudoku cannot be solved :(")
		print_sudoku(sudoku) 
