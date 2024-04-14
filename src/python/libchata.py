import preprocessing
import checks
import parse

class ChataProcessor:
    file_contents = []

    def compile(self, input: [[str]]):
        file_contents = preprocessing.run(input)

        checks.run(file_contents)

        parse.run(file_contents)

    def run(self, input):
        return input
    
