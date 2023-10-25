import matplotlib.pyplot as plt

def set_instruction_from_file(filename):
    # <insn name, frequency>
    dict = {}

    with open(filename) as file:
        for insn in file:
            if insn not in dict:
                dict[insn] = 1
            else:
                dict[insn] = dict[insn] + 1

    return dict

def get_most_frequent_instructions(insn_dict, number_of_elems):
    if number_of_elems > len(insn_dict):
        number_of_elems = len(insn_dict)

    sorted_insn_dict_list = sorted(insn_dict.items(), key=lambda x:x[1], reverse=True)

    return sorted_insn_dict_list[:number_of_elems]

def create_chart(freq_insn):
    names = []
    values = []

    for i in range(len(freq_insn)):
        pair = freq_insn[i]
        names.append(pair[0])
        values.append(pair[1])

    fig, ax = plt.subplots(figsize=[10, 6])

    ax.barh(range(len(freq_insn)), [val for val in values], align='center', zorder=3)
    ax.set_yticks(range(len(freq_insn)), labels=names)
    ax.set_xlabel('Frequency')
    ax.set_title('IR traces -O2')

    plt.savefig("trace.png")
    plt.show()

    return

def main():
    insn_dict = set_instruction_from_file("insn.trace")
    freq_insn = get_most_frequent_instructions(insn_dict, 10)

    create_chart(freq_insn)

    return

if __name__ == '__main__':
    main()
