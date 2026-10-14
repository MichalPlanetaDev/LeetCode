public class Solution {
    public string RemoveDuplicates(string s, int k) {
        char[] chars = new char[s.Length];
        int[] counts = new int[s.Length];
        int size = 0;

        foreach (char c in s) {
            chars[size] = c;
            counts[size] = size > 0 && chars[size - 1] == c ? counts[size - 1] + 1 : 1;
            ++size;

            if (counts[size - 1] == k)
                size -= k;
        }

        return new string(chars, 0, size);
    }
}