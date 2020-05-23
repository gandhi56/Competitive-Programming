import java.util.Scanner

fun main() {
    val inp = Scanner(System.`in`)
    val t = inp.nextInt()
    for (tt in 1..t){
        var n = inp.nextInt()
        var d = 1
        var ans = mutableListOf<Int>()
        while (n > 0){
            if (n%10 > 0){
                ans.add((n%10)*d)
            }
            n /= 10
            d *= 10
        }

        println(ans.size)
        for (x in ans)
            print("$x ")
        println()
    }
}