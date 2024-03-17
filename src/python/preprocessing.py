import re

def run(input):
    global target_data
    target_data = input

    print("Preprocessing input:")
    for i in range(len(target_data)):
        print(target_data[i])

    remove_comments()

    add_injections()    

    print("Preprocessing result:")
    for i in range(len(target_data)):
        print(target_data[i])

    return target_data

def remove_comments():
    #comment format: # starts the comment for a line, and a second # cancels the comment
    #alternatively, ## makes the rest of the line a comment regardless of a second #

    for i in range(len(target_data)):
        lines = []
        #split by \n or \r\n
        lines = re.split(r'\n|\r\n', target_data[i])

        for j in range(len(lines)):
            #remove comment section of ##...
            lines[j] = re.sub(r'##.*', '', lines[j])

            #remove comment section of #...#
            lines[j] = re.sub(r'#.+#', '', lines[j])

        target_data[i] = '\n'.join(lines)

def add_injections():
    #injection adds another file to where the injection is
    #format: inject filename, where filename is the name of the file to inject

    for i in range(len(target_data)):
        lines = []
        #split by \n or \r\n
        lines = re.split(r'\n|\r\n', target_data[i])

        for j in range(len(lines)):
            #inject file
            injection_source = re.search(r'inject (.+)', lines[j])
            if injection_source:

                with open(injection_source.group(1), 'r') as f:
                    injection_data = f.read()
                lines[j] = injection_data
            
        target_data[i] = '\n'.join(lines)