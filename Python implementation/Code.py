def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]
def combSort(arr):
    gap = len(arr)
    shrink = 1.3
    swapped = True

    while gap > 1 or swapped:
        gap = int(gap / shrink)
        if gap < 1:
            gap = 1

        swapped = False

        for i in range(len(arr) - gap):
            if arr[i] > arr[i + gap]:
                swap(arr, i, i + gap)
                swapped = True
def printArrayToFile(arr, filename):
    with open(filename, 'w') as outFile:
        for array in arr:
            outFile.write(' '.join(map(str, array)) + '\n')
    print("Sorted arrays have been written to", filename)

if __name__ == "__main__":
    try:
        with open("input.txt","r") as file:
            arrays = []
            lines = file.readlines()
            for line in lines:
                arr = list(map(int, line.split()))[1:] 
                arrays.append(arr)
    except FileNotFoundError:
        print("Error: Unable to open the file input.txt")
        exit(1)
    for arr in arrays:
        combSort(arr)
    printArrayToFile(arrays, "output.txt")
