//
//  ViewController.swift
//  VideoRecorder
//
//  Created by 马良 on 2020/10/9.
//

import Cocoa

class ViewController: NSViewController {

    var recStatus = false
    var thread: Thread?
    let btn = NSButton.init(title: "Record", target: nil, action: #selector(onClick))

    override func viewDidLoad() {
        super.viewDidLoad()

        view.setFrameSize(NSSize(width: 320, height: 240))

        btn.title = "开始录制"
        btn.frame = NSRect(x: 320 / 2 - 60, y: 240 / 2 - 15, width: 120, height: 30)
        btn.bezelStyle = .rounded
        btn.setButtonType(.pushOnPushOff)
        btn.target = self

        view.addSubview(btn)
    }

    @objc func onClick() {
        recStatus = !recStatus
        if recStatus {
            btn.title = "停止录制"
            thread = Thread.init(target: self, selector: #selector(recAudio), object: nil)
            thread?.start()
        } else {
            btn.title = "开始录制"
            set_status(0)
        }
    }

    @objc func recAudio() {
        open_media()
    }

    override var representedObject: Any? {
        didSet {
            // Update the view, if already loaded.
        }
    }


}

