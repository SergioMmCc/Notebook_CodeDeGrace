import java.util.*

fun solver() {
    val n = readLine()!!.toInt()
    val a = readLine()!!
    val b = readLine()!!

    var ans = 0
    var last = a[0]
    var count = 1

    for (i in 1 until n) {
        if (a[i] == last) {
            count++
        } else {
            ans += count - 1
            count = 1
            last = a[i]
        }
    }

    ans += count - 1
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solver()
    }
}
