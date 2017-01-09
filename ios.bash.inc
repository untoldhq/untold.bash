# Aliases
alias bef="bundle exec fastlane"

# Commands
ios() {
  assets=$(dirname $BASH_SOURCE)
  assets="$assets/ios_assets"
  if [ -z "$1" ]                           # Is parameter #1 zero length?
  then
      echo "Usage: ios project-name"  # Or no parameter passed.
      return -1
  fi
  target=$1
  project=$(ls | grep xcodeproj)

  if [ -z "$project" ]                           # Is parameter #1 zero length?
  then
      echo "Error: Couldn't find an Xcode Project in the current directory"  # Or no parameter passed.
      return -1
  fi

  cp -n "$assets/.gitignore" .
  cp -n "$assets/Gemfile" .
  cp -n "$assets/Podfile" .
  cp -nR "$assets/fastlane" .
  mkdir -p Changelogs
  touch Changelogs/.keep

  echo ""
  echo "${BOLD}Third Party Dependencies$RESET"
  echo "${BOLD}========================$RESET"
  realm=$(us_yn_prompt "Do you need Realm (local data ORM)?")
  echo ""
  json=$(us_yn_prompt "Do you need to parse JSON (Decodable)?")
  echo ""
  networking=$(us_yn_prompt "Do you need to non-basic networking (Alamofire)?")
  echo ""

  pods=""
  if [ "$realm" == "1" ]
  then
    pods="  pod 'RealmSwift'"
  fi

  if [ "$json" == "1" ]
  then
    pods="$pods<br>pod 'Decodable'"
  fi

  if [ "$networking" == "1" ]
  then
    pods="$pods<br>pod 'Alamofire'"
  fi

  sed -i '' "s/<TARGET>/$target/g" Podfile
  sed -i '' "s/<PODS>/$pods/g" Podfile
  sed -i '' -e 's/<br>/\'$'\n\t/g' Podfile

  echo ""
  echo "${BOLD}       AUTOMATION       $RESET"
  echo "${BOLD}========================$RESET"
  match=$(us_yn_prompt "Use Match to manage codesigning? (If you don't know, yes)?")
  
  bundle install --path vendor/bundle
  bundle exec pod install

  password=$(us_gen_password)
  echo "$password" | pbcopy
  echo "Your new match passphrase is $BOLD$BRAND$password$RESET"
  echo "It has been copied to your clipboard, save it, and paste it when prompted"

  return 0
}

ios_reset() {
  project=$(ls | grep xcodeproj)

  if [ -z "$project" ]                           # Is parameter #1 zero length?
  then
      echo "Error: Couldn't find an Xcode Project in the current directory"  # Or no parameter passed.
      return -1
  fi

  # echo "Are you sure?"
  # reset=$(us_yn_prompt "This will remove fastlane, your Gemfile, Podfile, and gitignore.")
  # echo ""

  # if [ "$reset" == "0" ]
  # then
  #   return 0
  # fi
  rm -rf fastlane
  rm -rf Changelogs
  rm -f Gemfile
  rm -f Podfile
  rm -f .gitignore

  return 0
}

us_gen_password() {
    password="$(us_random_word) $(us_random_word) $(us_random_word) $(us_random_word)"
    echo "$password"
    return 0
}

us_random_word() {
    #This is horribly ineffecient, we should find a way to only fetch the list once, but I'm bad at bash.
    line_count="$(cat /usr/share/dict/words | grep '^[a-z]\{4,6\}$' | wc -l)"
    line="$((${RANDOM} % ${line_count} + 1))"
    random_line=$(cat /usr/share/dict/words | grep '^[a-z]\{4,6\}$' | sed -n ${line}p)
    echo $random_line
    return 0
}
