import libchata
import sys

def main():
    print("This is the Python implementation of Chata!")

    sample_data = [1, 2, 3]

    target_files = sys.argv[1:]

    target_data = []

    for file in target_files:
        with open(file, 'r') as f:
            target_data.append([file, f.read()])

    processor = libchata.ChataProcessor()

    processor.compile(target_data)

    sample_data = processor.run(sample_data)

if __name__ == "__main__":
    main()