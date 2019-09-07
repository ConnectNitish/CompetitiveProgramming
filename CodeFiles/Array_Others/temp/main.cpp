class Solution
{
public:
  int lowbit (int x)
  {
    return x & (-x);
  }

  void update (int s[], int i, int n)
  {
    while (i <= n)
      {
	s[i]++;
	i = i + lowbit (i);
      }
  }

  int res (int s[], int t)
  {
    int ans = 0;
    while (t > 0)
      {
	ans = ans + s[t];
	t = t - lowbit (t);
      }
    return ans;
  }
  unordered_map < int, int >q;
  vector countSmaller (vector & nums)
  {
    int k;
    k = nums.size ();
    vector p;
    if (k == 0)
      return p;
    int i, j, d;
    int a[k];
    for (i = 0; i < k; i++)
      a[i] = nums[i];
    sort (a, a + k);
    j = 0;
    for (i = 0; i < k; i++)
      if (q[a[i]] == 0)
	q[a[i]] = ++j;
    int s[j + 1];
    memset (s, 0, sizeof (s));
    for (i = k - 1; i >= 0; i--)
      {
	d = res (s, q[nums[i]]);
	p.push_back (d);
	update (s, q[nums[i]] + 1, j);
      }
    reverse (p.begin (), p.end ());
    return p;
  }
};
