sokobanSpace = [[0 for x in range(3)] for y in range(3)]
transitions = list()

""" 

P - Player
R - Rock
W - Wall
N - Nothing

"""
"""
#pushing rock right transitions
for x in range(0, len(sokobanSpace)):
    for y in range(0, len(sokobanSpace[x])-2):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "P R N "
                i += 3

        transitionString += "=> "
        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N P R "
                i += 3

        transitionString += " LABEL ROCKRIGHT"

        transitions.append(transitionString)


#pushing rock left transitions
for x in range(0, len(sokobanSpace)):
    for y in range(0, len(sokobanSpace[x])-2):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N R P "
                i += 3

        transitionString += "=> "
        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "R P N "
                i += 3

        transitionString += " LABEL ROCKLEFT"

        transitions.append(transitionString)



#pushing rock up transitions
for x in range(0, len(sokobanSpace)-2):
    for y in range(0, len(sokobanSpace[x])):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        #9 = map biggest line/column length squared
        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += "=> "
        i = 0

        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "N "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += " LABEL ROCKUP"

        transitions.append(transitionString)
      


#pushing rock down transitions
for x in range(0, len(sokobanSpace)-2):
    for y in range(0, len(sokobanSpace[x])):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        #9 = map biggest line/column length squared
        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "N "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += "=> "
        i = 0

        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += " LABEL ROCKDOWN"

        transitions.append(transitionString)

"""

#player only movement



#moving right transitions
for x in range(0, len(sokobanSpace)):
    for y in range(0, len(sokobanSpace[x])-1):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "P N  "
                i += 2

        transitionString += "=> "
        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N P "
                i += 2

        transitionString += " LABEL MOVERIGHT"

        transitions.append(transitionString)


#moving left transitions
for x in range(0, len(sokobanSpace)):
    for y in range(0, len(sokobanSpace[x])-1):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N P "
                i += 2

        transitionString += "=> "
        i = 0

        while(i < 9):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "P N "
                i += 2

        transitionString += " LABEL MOVELEFT"

        transitions.append(transitionString)



#pushing rock up transitions
for x in range(0, len(sokobanSpace)-2):
    for y in range(0, len(sokobanSpace[x])):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        #9 = map biggest line/column length squared
        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += "=> "
        i = 0

        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "N "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += " LABEL ROCKUP"

        transitions.append(transitionString)
      


#pushing rock down transitions
for x in range(0, len(sokobanSpace)-2):
    for y in range(0, len(sokobanSpace[x])):
        index = x * len(sokobanSpace[0]) + y
        transitionString = ""

        i = 0

        #9 = map biggest line/column length squared
        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "N "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += "=> "
        i = 0

        while(i < 16):
            if(not(i == index)):
                transitionString += "- "
                i += 1

            else:
                transitionString += "N "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "P "
                for z in range(0, len(sokobanSpace)-1):
                    transitionString += "- "
                transitionString += "R "
                i += 2 * (len(sokobanSpace)-1) + 3

        transitionString += " LABEL ROCKDOWN"

        transitions.append(transitionString)









print(transitions)


