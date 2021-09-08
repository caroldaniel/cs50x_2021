import cs50
import csv
import sys


def main():
    # Check for error
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    
    strs = []
    profiles = []
    
    # Open database and populate the lists
    with open(sys.argv[1], "r") as database:
        data_reader = csv.DictReader(database)
        # Populate list of Short Tandem Repeat (STRs)
        strs = data_reader.fieldnames[1:]
        # for i in range(len(strs)):
        #     print(f"{strs[i]}")
        # Populate list of profiles
        for row in data_reader:
            profiles.append(row)
        # for i in range(len(profiles)):
        #     print(f"{profiles[i]}")
    
    # Initialize counter of STRs
    str_counter = dict.fromkeys(strs, 0)

    with open(sys.argv[2], "r") as sequence_file:
        sequence = sequence_file.readline()
        # Find matches for every STR from database
        for str in strs:
            str_counter[str] = find_repeats(sequence, str)
    
    for profile in profiles:
        match_count = 0

        for str in strs:
            if int(profile[str]) != str_counter[str]:
                continue
            match_count += 1
        if match_count == len(strs):
            print(f"{profile['name']}")
            sys.exit(0)
    
    sys.exit("No match")
  
          
def find_repeats(sequence, str):
    # Find skip of the current STR
    str_len = len(str)
    
    max_repeats = 0
    for i in range(len(sequence)):
        # Zero the current repeat counter
        repeats = 0
        # Check if the current position is a match to the STR
        if sequence[i: i + str_len] == str:
            repeats += 1
            # Check if the sequence keeps repeating
            while sequence[i: i + str_len] == sequence[i + str_len: i + (2 * str_len)]:
                repeats += 1
                i += str_len
        # Update the maximum repeat counter if current is greater
        if repeats > max_repeats:
            max_repeats = repeats
    
    return max_repeats


if __name__ == "__main__":        
    main()