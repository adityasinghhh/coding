pointList = [(2,3), (5,4), (9,6), (4,7), (8,1), (7,2)]


class Node:
    location = None
    rightChild = None
    leftChild = None
    
 
def kdtree(pointList, depth=0, whichchild='m',parentline = 0):
    # Input Check
    if not pointList:
        return
 
    # Single point kdtree 
    if len(pointList) == 1:
        node = Node()
        node.location = pointList[0]
        return node
    
    # Select axis based on depth so that axis cycles through all valid values
    k = len(pointList[0]) # assumes all points have the same dimension
    axis = depth % k
 
    # Sort point list and choose median as pivot element
    pointList.sort(key=lambda point: point[axis])
    median = (len(pointList)+1) / 2 -1 # choose median
 
 
    # Create node and construct subtrees
    node = Node()
    node.location = pointList[median]
    #leftChild consists of kdtree of all points less than or equal to current node / median point
    node.leftChild = kdtree(pointList[0:median+1], depth+1,'l',pointList[median][axis])
    #rightChild consists of kdtree of all points strictly greater than current node
    node.rightChild = kdtree(pointList[median+1:], depth+1,'m',pointList[median][axis])
    return node
    

def search_kdtree(root, query_range):
    if not root:
        return
        
    stack = []
    stack.append(root)
    
    while stack:
        temp = stack.pop()
        if not (temp.rightChild or temp.leftChild):
            print "Leaf :",temp.location
            # if temp lies in query_range, add it to solution 
        else:
            if temp.rightChild:
                #if region(temp.rightChild) contained in query_range, add subtree(temp.rightChild) to solution
                #else if region(temp.rightChild) intersects with query_range :
                stack.append(temp.rightChild)
            if temp.leftChild:
                #if region(temp.leftChild) contained in query_range, add subtree(temp.leftChild) to solution
                #else if region(temp.leftChild) intersects with query_range :
                stack.append(temp.leftChild)
            print temp.location
    
    # return solution
    
    

def main():
    # Set pointList and query_range for individual test cases
    tree = kdtree(pointList)
    search_kdtree(tree,query_range)

if __name__ == "__main__":
    main()
