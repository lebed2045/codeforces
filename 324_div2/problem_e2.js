res1 = [],res2 = [];
ind = [], need = [];
a = [],b = [];
ans = 0;
var n,i;

function _swap(i, j)
 {
    //swap(ind[a[i]],ind[a[j]]);
    var temp = ind[a[i]];
    ind[a[i]] = ind[a[j]];
    ind[a[j]] = temp;

    ans += Math.abs(j-i);
    res1.push(i);
    res2.push(j);
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
 }

function solve(i, j)
 {
  if (need[a[i]] >= j)
   {
    _swap(i,j);
    return;
   }
  for (var k=i;i<=j;k++)
   if (need[a[k]] >= j)
    {
     _swap(k,j);
     solve(i,k);
     return;
   }
 }

function main()
 {

    n = +readline();
  a = readline().split(" ").map(Number);
  b = readline().split(" ").map(Number);
  for (var i = a.length; i > 0; --i) {
    a[i] = a[i-1];
    b[i] = b[i-1];
    ind[a[i]]=i;
    need[b[i]]=i;
  }

  for (i=1;i<=n;i++)
   if (a[i] != b[i])
    solve(i,ind[b[i]]);

  //cout<<ans<<endl;
  write(ans + "\n");
  write(res1.length + "\n");
  for (var i=0;i<res1.length;i++)
    write(res1[i] + " " +res2[i] + "\n");
}

 main();