import matplotlib as plt

lomuto_n = []
lomuto_times = []
hoare_n = []
hoare_times = []
median_n = []
median_times = []

def populate_lomuto_set(stream):
    for line in stream:
        if "n" in line:
            # lomuto_n.append(?)
            pass
        elif "time" in line:
            # lomuto_times.append(?)
            pass
        else:
            return

def populate_hoare_set(stream):
    for line in stream:
        if "n" in line:
            # hoare_n.append(?)
            pass
        elif "time" in line:
            # hoare_times.append(?)
            pass
        else:
            return

def populate_median_set(stream):
    for line in stream:
        if "n" in line:
            # median_n.append(?)
            pass
        elif "time" in line:
            # median_times.append(?)
            pass
        else:
            return


def main():
    stream = open("output_structure.txt", "r")

    for line in stream:
        match line:
            case "lomuto:":
                populate_lomuto_set(stream)
            case "hoare:":
                populate_hoare_set(stream)
            case "median:":
                populate_median_set(stream)
            case other:
                print(f"Error: partition type not recognized...")

main()