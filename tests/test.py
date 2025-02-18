#!/usr/bin/python3

import random
import subprocess
import sys

MIN_INT = -2**31
MAX_INT = 2**31 - 1

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OK = '\033[92m'
    WARNING = '\033[93m'
    KO = '\033[91m'
    END = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def test_ok(tests, numbers):
	results = []

	for i in range(tests):
		random_numbers = random.sample(range(MIN_INT, MAX_INT + 1), numbers)
		random_numbers_str = ' '.join(map(str, random_numbers))

		try:
			push_swap_process = subprocess.Popen(["./push_swap", random_numbers_str], stdout=subprocess.PIPE, text=True)
			
			checker_process = subprocess.Popen(["./checker_linux", random_numbers_str], stdin=push_swap_process.stdout, stdout=subprocess.PIPE, text=True)

			output, _ = checker_process.communicate()

			results.append(output.strip("\n"));

			push_swap_process.stdout.close()

		except Exception as e:
			print(f"An error occurred: {e}")
	
	ok_count = results.count('OK')
	ok_pass = bcolors.OK if ok_count == tests else bcolors.KO
	print(f"OKs: {ok_pass}{ok_count}{bcolors.END}")

	ko_count = results.count('KO')
	ko_pass = bcolors.OK if ko_count == 0 else bcolors.KO
	print(f"KOs: {ko_pass}{ko_count}{bcolors.END}")

	return ok_count == tests


def test_lines(tests, numbers):
	results = []

	for i in range(tests):
		# Generate 100 unique random numbers within the range
		random_numbers = random.sample(range(MIN_INT, MAX_INT + 1), numbers)
		random_numbers_str = ' '.join(map(str, random_numbers))

		try:
			push_swap_process = subprocess.Popen(["./push_swap", random_numbers_str], stdout=subprocess.PIPE, text=True)
			
			wc_process = subprocess.Popen(["wc", "-l"], stdin=push_swap_process.stdout, stdout=subprocess.PIPE, text=True)
				
			output, _ = wc_process.communicate()

			push_swap_process.stdout.close()

			results.append(int(output));

		except Exception as e:
			print(f"An error occurred: {e}")

	benchmark = 0
	if numbers == 100:
		benchmark = 700
	elif numbers == 500:
		benchmark = 5500
	
	#print(f"List: {results}")
	if benchmark:
		max_val = max(results)
		max_pass = bcolors.OK if max_val < benchmark else bcolors.KO
		max_diff = max_val - benchmark
		print(f"Max: {max_pass}{max_val} ({max_diff:+}){bcolors.END}")

		avg_val = sum(results) / len(results)
		avg_pass = bcolors.OK if avg_val < benchmark else bcolors.KO
		avg_diff = avg_val - benchmark
		print(f"Avg: {avg_pass}{avg_val:.0f} ({avg_diff:+.0f}){bcolors.END}")

		min_val = min(results)
		min_pass = bcolors.OK if min_val < benchmark else bcolors.KO
		min_diff = min_val - benchmark
		print(f"Min: {min_pass}{min_val} ({min_diff:+}){bcolors.END}")

	print()


def test(tests, numbers):
	print(f"{tests} tests of {numbers} numbers:")
	ok = test_ok(tests, numbers)
	if ok:
		test_lines(tests, numbers)
	else:
		print()


tests = int(sys.argv[1])
test(tests, 1)
test(tests, 2)
test(tests, 3)
test(tests, 4)
test(tests, 5)
test(tests, 10)
test(tests, 100)
test(tests, 500)
