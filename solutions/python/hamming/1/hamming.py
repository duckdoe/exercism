def distance(strand_a, strand_b):
    d = 0  # represents the distance between the two strands

    if len(strand_a) != len(strand_b):
        raise ValueError("Strands must be of equal length.")

    for i in range(len(strand_a)):
        if strand_a[i] != strand_b[i]:
            d += 1

    return d
