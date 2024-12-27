bool isAnagram(char* s, char* t) {
    int tableS[26] = {0};
    int tableT[26] = {0};
    for (char* c = s; *c != '\0'; c++) {
        tableS[*c - 'a'] += 1;
    }
    for (char* c = t; *c != '\0'; c++) {
        tableT[*c - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (tableS[i] != tableT[i]) return false;
    }
    return true;
}