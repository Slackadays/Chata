import preprocessing
import checks

class ChataProcessor:
    file_contents = []

    def compile(self, input):
        file_contents = preprocessing.run(input)

        checks.run(file_contents)

    def run(self, input):
        return input