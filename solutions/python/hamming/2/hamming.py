def distance(strand_a, strand_b):
    strand_distance = 0  # represents the distance between the two strands

    if len(strand_a) != len(strand_b):
        raise ValueError("Strands must be of equal length.")

    for i in range(len(strand_a)):
        if strand_a[i] != strand_b[i]:
            strand_distance += 1

    return strand_distance
