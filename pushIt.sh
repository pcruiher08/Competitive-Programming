# a million commits
for Y in {2020..2020}
do
  mkdir $Y
  cd $Y
  for M in {5..7}
  do
    mkdir $M
    cd $M
    for D in {1..30}
    do
      mkdir $D
      cd $D
      for i in {08..09}
      do
        echo "$i on $M/$D/$Y" > commit.md
        export GIT_COMMITTER_DATE="$Y-$M-$D 12:$i:00"
        export GIT_AUTHOR_DATE="$Y-$M-$D 12:$i:00"
        git add commit.md -f
        git commit --date="$Y-$M-$D 12:0$i:00" -m "$i on $M $D $Y"
      done
      cd ../
    done
    cd ../
  done
  cd ../
done
git push origin master
git rm -rf 20**
git commit -am "cleanup"
git push origin master