import preprocessing
import checks
import sys

def main():
    print("This is the Python implementation of Chata!")

    target_files = sys.argv[1:]

    target_data = []

    for file in target_files:
        with open(file, 'r') as f:
            target_data.append(f.read())

    target_data = preprocessing.run(target_data)

    checks.run(target_data)

if __name__ == "__main__":
    main()