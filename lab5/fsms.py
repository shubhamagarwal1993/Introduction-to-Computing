# FSM simulator
import sys

initialState = ''

def readTransitions(transitionFileName):

    # check if file exists
    try:
        with open(transitionFileName, 'r'): pass

    except:
        print 'ERROR: Cannot open ' + transitionFileName
        exit()

    # access the global variable initialState
    global initialState
    transitions = {}
    f = open(transitionFileName, 'r')

    # read file line by line to obtain transitions
    for line in f:
        transition = str.split(line)
        if len(transition) < 3:
            continue
        # initialize initialState if it is empty
        if len(initialState) == 0:
            initialState = transition[0]
        transitions[(transition[0], transition[1])] = transition[2]

    # close file
    f.close()
    return transitions


def readOutputs(outputFileName):

    try:
        with open(outputFileName, 'r'): pass
                
    except:
        print 'ERROR: Cannot open ' + outputFileName
        exit()

    outputs = {}
    f = open(outputFileName, 'r')

    for line in f:
        output = str.split(line)
        if len(output) < 2:
            continue
        outputs[output[0]] = output[1]
    
    f.close
    return outputs



def fsmsim(string, current, edges, statemap, output, accepting):
    if current not in statemap:   
        return false
    
    output = output+statemap[current]
    if string == "":
        #return output == accepting
        return output
    else:
        letter = string[0]
        if(current, letter) in edges:
            destination = edges[(current,letter)]
            remaining_string = string[1:]
            return fsmsim(remaining_string, destination, edges, statemap, output, accepting)
        else:
            return 1 == 0


def main():
    # check user input
    if len(sys.argv) < 4:
        print 'ERROR: Missing files'
        print 'USAGE: python sms.py [state transition file] [state output file] [string]'
        exit()

    # get files name and input string
    stateTransitionFileName = sys.argv[1]
    stateOutputFileName = sys.argv[2]
    string = sys.argv[3]

    # Read transitions
    transitions = readTransitions(stateTransitionFileName)

    # Read outputs
    outputs = readOutputs(stateOutputFileName)

    # output result
    print fsmsim(string, initialState, transitions, outputs, '', '')


if __name__ == '__main__':
    main()
