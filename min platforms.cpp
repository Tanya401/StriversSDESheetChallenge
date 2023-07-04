int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    std::sort(at, at + n);
    std::sort(dt, dt + n);

    int platforms = 1;
    int maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            platforms++;
            i++;
            maxPlatforms = std::max(maxPlatforms, platforms);
        } else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}