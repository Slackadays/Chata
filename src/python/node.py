from enum import Enum
    
class Action(Enum):
    ADD = 1
    SUB = 2
    MUL = 3

class VariableType(Enum):
    REAL = 1
    INT = 2
    IMAG = 3
    CPLX = 4

class Variable:
    type = None
    value = 0
    name = None

class Node:
    varsAvailable = []
    action = None
    actionParams = []
    nextNodes = []