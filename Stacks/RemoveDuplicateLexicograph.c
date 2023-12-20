#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    int lastIndex[26] = {0};
    int seen[26] = {0};
    int len = strlen(s);
    
    // Store the last index of each character in the string
    for (int i = 0; i < len; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    char stack[26];
    int top = -1;

    for (int i = 0; i < len; i++) {
        int curr = s[i] - 'a';
        
        if (seen[curr]) continue;

        // Remove characters from the stack if they are greater than current character,
        // occur later in the string, and haven't been used yet
        while (top != -1 && stack[top] > s[i] && i < lastIndex[stack[top] - 'a']) {
            seen[stack[top] - 'a'] = 0;
            top--;
        }

        stack[++top] = s[i];
        seen[curr] = 1;
    }

    // Create the result string from the stack in reverse order
    char* result = (char*)malloc((top + 2) * sizeof(char)); // +1 for the string end '\0'
    int index = 0;
    while (top != -1) {
        result[index++] = stack[top--];
    }
    result[index] = '\0';

    // Reverse the result string to match the expected lexicographical order
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start++] = result[end];
        result[end--] = temp;
    }

    return result;
}

int main() {
    char s[] = "cbacdcbc";
    char* result = removeDuplicateLetters(s);
    printf("Output: %s\n", result);

    free(result); // Free the dynamically allocated memory for the result
    return 0;
}
