using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoSingleton<GameManager>
{
    [SerializeField]
    private GameObject LevelUISystem;

    private void Start()
    {
        StartCoroutine(CoGameStart());
    }

    private IEnumerator CoGameStart()
    {
        yield return new WaitForSeconds(15f);
        
        LevelUISystem.gameObject.SetActive(true);
        Time.timeScale = 0f;

        yield return new WaitUntil(() => !LevelUISystem.gameObject.activeSelf);
    }
}
