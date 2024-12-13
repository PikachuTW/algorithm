int myAtoi(char* s) {
    long long int num = 0;
    bool isPositive = true;
    bool started = false;
    for (char* c = s; c != NULL && *c != '\0'; c++) {
        if (started) {
            if (isdigit(*c)) {
                num *= 10;
                if (isPositive) {
                    num += *c - '0';
                } else {
                    num -= *c - '0';
                }
                if (num > INT_MAX) num = INT_MAX;
                if (num < INT_MIN) num = INT_MIN;
            } else {
                break;
            }
        } else {
            if (*c == ' ') continue;
            if (*c == '-') {
                isPositive = false;
            } else if (*c == '+') {
            } else if (isdigit(*c)) {
                if (isPositive) {
                    num += *c - '0';
                } else {
                    num -= *c - '0';
                }
            } else {
                break;
            }
            started = true;
        }
    }
    if (num > INT_MAX) num = INT_MAX;
    if (num < INT_MIN) num = INT_MIN;
    return (int)num;
}