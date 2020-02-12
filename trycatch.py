    try:
        number = int(s)
        if number < 1000000000 or number > 9999999999:
            print("NO")
            continue
    except Exception as ex