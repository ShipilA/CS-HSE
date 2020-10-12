using System;
using System.Collections.Generic;
using System.Linq;

partial class Program
{
    private static int GetMax(List<int> a)
    {
        int iMaxA = 0, i;
        for (i = 0; i < a.Count; ++i)
            if (a[i] >= a[iMaxA])
                iMaxA = i;
        return iMaxA;
    }
    public static List<int> toVector(int x)
    {
        List<int> ans = new List<int>();
        do
        {
            ans.Add(x % 10);
            x /= 10;
        }
        while (x > 0);
        return ans;
    }
    public static int toInt(List<int> a)
    {
        int n = 0;
        for (int i = a.Count - 1; i >= 0; --i)
            n = n * 10 + a[i];
        return n;
    }
    private static bool TryParseInput(string inputA, string inputB, out int a, out int b)
    {
        a = 0;
        b = 0;
        return (int.TryParse(inputA, out a) && int.TryParse(inputB, out b) && a >= 0 && b >= 0);
    }

    private static void SwapMaxDigit(ref int a, ref int b)
    {
        List<int> aa = toVector(a);
        List<int> bb = toVector(b);
        int maxA = 0, maxB = 0, i;
        maxA = aa.Max();
        maxB = bb.Max();
        for (i = 0; i < Math.Max(aa.Count, bb.Count); ++i)
        {
            if (aa.Count > i && aa[i] == maxA)
                aa[i] = maxB;
            if (bb.Count > i && bb[i] == maxB)
                bb[i] = maxA;
        }
        a = toInt(aa);
        b = toInt(bb);
    }
}
