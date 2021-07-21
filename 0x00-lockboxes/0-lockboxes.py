#!/usr/bin/python3
'''lockboxes module'''


def canUnlockAll(boxes):
	'''method that determins if all the boxes can be opened'''
	keys = [0]
	for box, listOfKeys in enumerate(boxes):
		if box not in keys:
			if not checkOtherBoxes(box, boxes, keys):
				return False
		keys += [x for x in listOfKeys if x not in keys]
	return True


def checkOtherBoxes(box, boxes, keys):
	'''checks if key to our current box is in a 
	box we havent seen yet, but can unlock'''
	for i in range(box + 1, len(boxes) - 1):
		for j in boxes[i]:
			if i in keys and j == box:
				return True
	return False
