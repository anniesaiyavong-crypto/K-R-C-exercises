

void reverse(char s[], int left, int right) {
    // base case
    if (left <= right)
        return;
    // swaping
    int temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    // narrow down
    reverse(s, left + 1, right - 1);
}
