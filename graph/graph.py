import matplotlib.pyplot as plt

lomuto_n = []
lomuto_times = []
hoare_n = []
hoare_times = []
median_n = []
median_times = []

def populate_lomuto_set(stream):
    for line in stream:
        if "\n".__eq__(line):
            return
        else:
            line_list = line.split(" ", 1)
            lomuto_n.append(int(line_list[0]))
            lomuto_times.append(float(line_list[1][:-1]))

def populate_hoare_set(stream):
    for line in stream:
        if "\n".__eq__(line):
            return
        else:
            line_list = line.split(" ", 1)
            hoare_n.append(int(line_list[0]))
            hoare_times.append(float(line_list[1][:-1]))

def populate_median_set(stream):
    for line in stream:
        if "\n".__eq__(line):
            return
        else:
            line_list = line.split(" ", 1)
            median_n.append(int(line_list[0]))
            median_times.append(float(line_list[1][:-1]))


def main():
    stream = open("../output.txt", "r")

    for line in stream:
        match line:
            case "lomuto:\n":
                populate_lomuto_set(stream)
            case "hoare:\n":
                populate_hoare_set(stream)
            case "median:\n":
                populate_median_set(stream)
            case other:
                print(f"Error: {line} instruction not recognized...\n")

    plt.plot(lomuto_n, lomuto_times, color='green', linestyle='solid', linewidth = 1, label='lomuto')
    plt.plot(hoare_n, hoare_times, color='red', linestyle='solid', linewidth = 1, label='hoare')
    plt.plot(median_n, median_times, color='blue', linestyle='solid', linewidth = 1, label='median')
    plt.legend()
    
    plt.xlim(0, 1000)
    plt.xlabel("SET SIZE")

    plt.ylim(0, .006)
    plt.ylabel("SORTING TIME")

    plt.title("Comparing Speeds of Partitions as Sets Increase")
    plt.show()

main()