a c d = s1

1 0 2 1 0 0 0 0 1 0 0 0 ... 1

c h z = s2
a c c d h z

1. Point to s1
2. Point to s2
3. Loop in the both strings and compare each strings
4. Keep comparing each char holding in the pointers until you have finished both or one
5. If you havent finished with one then append the rest of chars
6. Return the result

string mergedSortedStrings(string s1, string s2){
    string result;

    if (s1.length() == 0 && s2.legth() == 0)
        return result;
    
    int first = 0;
    int second = 0;

    while (first < s1.length() && second < s2.length()){
        if (s1[first] < s2[second]) {   
            result += s1[first];
            first++;
        } else if (s2[second] < s1[first] ){
            result += s2[second];
            second++;
        } else {
            result += s1[first];
            result += s2[second];
            first++;
            second++;
        }
    }

    if (first < s1.length()) {
        for (int i = first; i < s1.length(); i++)
            result += s1[i]
    } else if (second < s2.legth()){
        for (int i = second; i < s2.length(); i++)
            result += s1[i]
    }

    return result;
}

//https://www.geeksforgeeks.org/bucket-sort-2/
1. Create an array of 26 size
2. Loop in each of the arrays and update your array of chars
3. Build the resulting string from the hashmap
4. Return the merged string

string mergedStrings(string str1, string str2){
    string mergedString;
    int ocurrences[26] = {0};

    for (char c : str1) {
        ocurrences[c - 'a'] += 1;
    }

    for (char c : str2) {
        ocurrences[c - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++){
        while (ocurrences[i] != 0){
            mergedString += char(i + 'a');
            ocurrences[i] -= 1;
        }
    }
    
    return mergedString;
}