class Solution {
    fun toPhrase(s: String): String {
        val lowerCase = s.toLowerCase()
        val re = Regex("[^A-Za-z0-9 ]")
        val onlyAlphabet = re.replace(lowerCase, "")
        val withoutBlank = onlyAlphabet.filter { !it.isWhitespace() }
        return withoutBlank
    }
    
    fun isPalindrome(s: String): Boolean {
        val phraseResult = toPhrase(s)
        
        val sb = StringBuilder(phraseResult)
        val reversedResult = sb.reverse().toString()
        print(reversedResult)
        
        if (phraseResult.equals(reversedResult))
            return true
        else
            return false
    }
}