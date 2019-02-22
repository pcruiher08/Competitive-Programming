using System;
using System.Collections;

namespace ciphering
{
    class Program
    {
        
        static void Main(string[] args)
        {
            //Console.WriteLine(cipher(""));
            ArrayList ans = new ArrayList();
            while (true)
            {
                string a = Console.ReadLine();
                if (a == null) break;
                ans.Add(cipher(a));
            }
            for (int i = 0; i < ans.Count; i++)
            {
                Console.WriteLine(ans[i]);
            }
        }

        static string cipher(string source)
        {
            string res = "";
            char[] aux = new char[source.Length];
            cipher_core(source.ToCharArray(), aux, 0, source.Length - 1, 0, source.Length - 1);
            for (int i = 0; i < aux.Length; i++)
            {
                if (aux[i] == 'a')
                {
                    res += 'z';
                    continue;
                }
                if (aux[i] == 'A')
                {
                    res += 'Z';
                    continue;
                }                    
                res += char.IsLetter(aux[i]) ? ((char)(aux[i] - 1)) : aux[i];
            }
            return res;
        }

        static void cipher_core(char[] source, char[] dest, int i, int j, int i1, int j1)
        {
            if (j < i)
                return;
            dest[i1 + (j - i) / 2] = source[i];
            cipher_core(source, dest, i + 1, (i + j) / 2, i1, (i1 + j1) / 2 - 1);
            cipher_core(source, dest, (i + j) / 2 + 1, j, (i1 + j1) / 2 + 1, j1);                        
        }
    }
}