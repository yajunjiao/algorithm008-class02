func isAnagram(s string, t string) bool {
   if len(s) != len(t) {
       return false
   }

   counter := [26]int{}
   for _, v := range s {
       counter[v - 'a']++
   }

   for _, v := range t {
       counter[v - 'a']--
       if counter[v - 'a'] < 0 {
           return false
       }
   }

   return true
}